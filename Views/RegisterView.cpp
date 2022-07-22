#include<string>
#include<vector>
#include"../Controllers/Register.hpp"
#include"../Models/CipherText.hpp"
#include"RegisterView.hpp"
using namespace std;

RegisterView::RegisterView()
{

}

RegisterView::~RegisterView(){

}

//显示基本界面并读入信息
void RegisterView::ShowRegister(shared_ptr<UserManager>& aUserManager) const
{
    string Name;//临时变量，暂存姓名
    string ID;//临时变量，暂存身份证号
    CipherText Password;//临时变量，暂存密码
    cout << "请输入身份证号、姓名和密码以注册一个新用户." << endl;
    cout << "身份证号:" ;
    cin >> ID;//读入用户输入的身份证号
    cout << "姓名:";
    cin >> Name;//读入用户输入的姓名
    cout << "密码:";
    cin >> Password;//读入用户输入的密码
    Register aReg;//创建一个Register(control类)的实例

    //访问冲突
    aReg.RegisterNewUser(aUserManager, ID, Name, Password);//调用函数，创建新用户
}

