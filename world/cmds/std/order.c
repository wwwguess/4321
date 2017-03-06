// order.c
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest,bb, aa,cmd;
	object ob;
        int a,b,c; 
	if( me != this_player(1) ) return 0;
  
	if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
		return notify_fail("指令格式：order <某人> to <指令>\n");
        if (me->query("class")!="officer") return notify_fail ("你不是朝庭命官，不能下命令\n");	
        if( !(ob = present(dest, environment(me))) )
		return notify_fail("这里没有 " + dest + "　\n");
	//obc = LOGIN_D->find_body(arg);
        if (ob->query("id")=="herbalist yang")
            return notify_fail(HIY "对方不听您的命令。 \n" NOR);   
        if (ob->query("id")=="Zhu hongxue")
            return notify_fail(HIY "对方不听您的命令。 \n" NOR);
	if (ob->query("combat_exp") >= 1000000)
            return notify_fail("你算什么东西，朝廷命官就能指挥我吗？");
        if (interactive(ob) ) {if (ob->query("class")!="officer") 
   	    return notify_fail("这个玩家不是官员，不能下命令！ 　\n");}
        if( !living(ob) )
		return notify_fail("这个物件不能执行命令　\n");
	//if( wiz_level(me) <= wiz_level(ob) )
        //		return notify_fail("你没有强制" + ob->name() + "执行命令的权力　\n");
        a=me->query_skill("yongren");b=me->query_skill("binfa");
        if ((a*b*a*b/10+me->query("combat_exp")) < ob->query("combat_exp")*2)
            return notify_fail("对方好象不听你的命令!\n");
        sscanf(cmd,"%s %s",aa,bb);   
       if (aa=="abandon") return notify_fail("不能命令对方用abandon指令！\n");	
       if (aa=="follow") return notify_fail("不能下follow命令！　\n");
       if( userp(ob) ){
    	log_file("FORCE_PLAYER", sprintf("[%s] %s forces %s to %s\n",  
	ctime(time()), geteuid(me), geteuid(ob), cmd));}
       tell_object(me,"你下了一道命令给"+ob->query("name")+"\n");
       tell_object(me,ob->query("name")+"说道：尊命！"+me->query("name")+"大人！\n");
       tell_object(ob,me->query("name")+"向你下令："+cmd+"\n"+"人在官场，身不由己啊！你只好听令了！\n");
       return ob->force_me(cmd);
}

int help(object me)
{
	write(@Help
指令格式：order <某人> to <指令>

命令某人做某事, 但你必须是官, 而且必须是在同一个房间里　
Help
	);
	return 1;
}
