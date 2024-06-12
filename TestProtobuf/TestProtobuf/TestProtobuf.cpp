#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "protobufdes/PBAccount.pb.h"

class TestName
{
public:
    TestName();
    ~TestName();

private:

};

TestName::TestName()
{
    cout << __FUNCTION__ << endl;
}

TestName::~TestName()
{
    cout << __FUNCTION__ << endl;
}

google::protobuf::Message* CreateMessage(const std::string& type_name)
{

    google::protobuf::Message* message = NULL;
    const google::protobuf::Descriptor* descriptor = google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(type_name);
    if (descriptor)
    {
        const google::protobuf::Message* prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
        if (prototype)
        {
            message = prototype->New();
        }
    }
    return message;
}

int main()
{
    Account::SynServerLog_Game2Gate ssg;
    ssg.set_uid(20);
    ssg.set_uparam(30);
    ssg.set_slog("sadas");

    TestName testName;

    size_t s32Len = ssg.ByteSizeLong();
    auto pData = std::make_unique<char[]>(s32Len);
    ssg.SerializeToArray(pData.get(), s32Len);

    cout << pData << endl;

    string str;
    ssg.SerializePartialToString(&str);
    cout << str << endl;
    
    Account::SynServerLog_Game2Gate ssg2;
    ssg2.ParseFromString(str);
    cout << ssg2.uid() << endl;
    cout << ssg2.uparam() << endl;
    cout << ssg2.slog() << endl;

    Account::TestMessage testmsg1;
    testmsg1.set_testid(1);
    size_t test_size = testmsg1.ByteSizeLong();
    string strTest = testmsg1.SerializeAsString();

    cout << "11111111111111111111111" << endl;

    Account::TestMessage testmsg2;
    testmsg2.ParseFromString(strTest);
    cout << testmsg2.testid() << endl;
    google::protobuf::Message* msg = CreateMessage(testmsg1.GetTypeName());

    delete msg;
    msg = nullptr;

    
    system("pause");
    return 0;
}