#pragma once
#ifdef _WIN64
#pragma comment(lib, "plfl64.lib")
#else
#pragma comment(lib, "plfl32.lib")
#endif


#define Plfl extern "C"
Plfl long	WINAPI P_LoadSystem(char *server_ip,long server_port,char *transfer_password,char *software_signature,char *additional_configuration,long clock_validation);//飘零旗舰网络初始化
Plfl char* WINAPI P_GetLoginValue(long type);													            //飘零旗舰取登录信息(类型)
Plfl long	WINAPI P_UserLogin(char* user_name, char* password);								                    //飘零旗舰用户登录(用户名,密码)
Plfl long	WINAPI P_IsLogin();													                            //飘零旗舰是否登录()
Plfl char* WINAPI P_UserReg(char* user_name, char* password, char* recharge_key, char* game_number, char* agent, char* contact_information);	//飘零旗舰用户注册(用户名,密码,充值卡密,游戏号,代理商,联系方式)
Plfl char* WINAPI P_ChangeBinding(char* user_name, char* password, char* game_number);					                //飘零旗舰用户解绑(用户名,密码,游戏号)
Plfl char* WINAPI P_CardReCharge(char* user_name, char* recharge_key, char* extension_worker);			                    //飘零旗舰用户充值(用户名,充值卡密,推广人员)
Plfl char* WINAPI P_ChangePwd(char* user_name, char* original_password, char* new_password, long type);		                //飘零旗舰用户改密(用户名,原始密码,新设密码,类型)
Plfl char* WINAPI P_GetDataValue(long type);										                        //飘零旗舰取数据(类型)
Plfl long	WINAPI P_CheckAgain();													                        //飘零旗舰二次效验()
Plfl char* WINAPI P_GetInfo(long type);										                            //飘零旗舰取软件信息(类型)
Plfl char* WINAPI P_ApiCall(char* function_name, char* parameter);                                                      //飘零旗舰执行动态函数(函数名,参数)
Plfl long	WINAPI P_Checktime();													                        //飘零旗舰过期检测()
Plfl long	WINAPI P_Timingbox(char* reminder_information, long waiting_time);				       	                        //飘零定时信息框(提示信息,等待时长)
Plfl long	WINAPI P_IsConnectNet();													                    //飘零旗舰网络检测()
Plfl long	WINAPI P_ExitLogin();													                        //飘零旗舰退出登录()
Plfl char* WINAPI P_GetPluginVer();										                                //飘零取插件版本号()
Plfl long	WINAPI P_MemoryStrFree(char* memory_point);				       	                                    //飘零内存文本释放(内存指针)
Plfl long	WINAPI P_Discount(char* user_name, char* password, long check_the_number);								            //飘零旗舰用户扣点(用户名,密码,点数)
Plfl char* WINAPI P_GetExpireTime(char* user_name, long type);		                                            //飘零旗舰查询到期时间(用户名,类型)
Plfl char* WINAPI P_ResetCode(char* user_name);		                                                        //飘零旗舰取安全码(用户名)
Plfl char* WINAPI P_JoinBlackList(long type);										                        //飘零旗舰加入黑名单(类型)
Plfl char* WINAPI P_SetDataValue(long type, char* text_data);										        //飘零旗舰置数据(类型,文本数据)

//Plfl long	WINAPI P_LoadSystem(char *服务器IP,long 服务器端口,char *传输密码,char *软件签名,char *附加配置,long 时钟效验);//飘零旗舰网络初始化
//Plfl char*	WINAPI P_GetLoginValue(long 类型);													            //飘零旗舰取登录信息(类型)
//Plfl long	WINAPI P_UserLogin(char* 用户名,char* 密码);								                    //飘零旗舰用户登录(用户名,密码)
//Plfl long	WINAPI P_IsLogin();													                            //飘零旗舰是否登录()
//Plfl char*	WINAPI P_UserReg(char* 用户名,char* 密码,char* 充值卡密,char* 游戏号,char* 代理商,char* 联系方式);	//飘零旗舰用户注册(用户名,密码,充值卡密,游戏号,代理商,联系方式)
//Plfl char*	WINAPI P_ChangeBinding(char* 用户名,char* 密码,char* 游戏号);					                //飘零旗舰用户解绑(用户名,密码,游戏号)
//Plfl char*	WINAPI P_CardReCharge(char* 用户名,char* 充值卡密,char* 推广人员);			                    //飘零旗舰用户充值(用户名,充值卡密,推广人员)
//Plfl char*	WINAPI P_ChangePwd(char* 用户名,char* 原始密码,char* 新设密码,long 类型);		                //飘零旗舰用户改密(用户名,原始密码,新设密码,类型)
//Plfl char*	WINAPI P_GetDataValue(long 类型);										                        //飘零旗舰取数据(类型)
//Plfl long	WINAPI P_CheckAgain();													                        //飘零旗舰二次效验()
//Plfl char*	WINAPI P_GetInfo(long 类型);										                            //飘零旗舰取软件信息(类型)
//Plfl char*	WINAPI P_ApiCall(char* 函数名,char* 参数);                                                      //飘零旗舰执行动态函数(函数名,参数)
//Plfl long	WINAPI P_Checktime();													                        //飘零旗舰过期检测()
//Plfl long	WINAPI P_Timingbox(char* 提示信息,long 等待时间);				       	                        //飘零定时信息框(提示信息,等待时长)
//Plfl long	WINAPI P_IsConnectNet();													                    //飘零旗舰网络检测()
//Plfl long	WINAPI P_ExitLogin();													                        //飘零旗舰退出登录()
//Plfl char*	WINAPI P_GetPluginVer();										                                //飘零取插件版本号()
//Plfl long	WINAPI P_MemoryStrFree(char *内存指针);				       	                                    //飘零内存文本释放(内存指针)
//Plfl long	WINAPI P_Discount(char* 用户名,char* 密码,long 点数);								            //飘零旗舰用户扣点(用户名,密码,点数)
//Plfl char*	WINAPI P_GetExpireTime(char* 用户名,long 类型);		                                            //飘零旗舰查询到期时间(用户名,类型)
//Plfl char*	WINAPI P_ResetCode(char* 用户名);		                                                        //飘零旗舰取安全码(用户名)
//Plfl char*	WINAPI P_JoinBlackList(long 类型);										                        //飘零旗舰加入黑名单(类型)
//Plfl char*	WINAPI P_SetDataValue(long 类型,char* 文本数据);										        //飘零旗舰置数据(类型,文本数据)