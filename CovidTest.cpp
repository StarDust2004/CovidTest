#include "./Views/LoginView.hpp"
#include <iostream>
using namespace std;

int main()
{
    // This is the main func
    LoginView aLogin;
    aLogin.ShowLogin();
    return 0;
}
/*debuging:
//TesteeView::ShowTest::    //debuging:采样时间赋值似乎出现了问题->DateTime类赋值函数？
//【已解决】PortalView::ShowPortal具有多种身份时遗漏了Testee
//TubeManager::LoadFromFile无内容时抛出异常语句修改为“No Tube in File:"+TubesFileName
//UserManager::LoadFromFile无内容时抛出异常语句修改为“No User in File:"+UsersFileName
//TesteeView


*/