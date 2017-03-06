//ROOM:/d/suzhou/shuidi.c
//by dwolf
//97.11.8 
         
#include <ansi.h>
inherit ROOM;    

string *make_msg = ({
    HIG "��û���ϵ���ƽ����ˮһ��������Ϳ�������������\n\n" NOR,
    HIG "���ʱ���������˿�ȥ��\n\n" NOR,	
    HIG	"���ڼ���������������������\n\n" NOR,
    HIG "��Ǻ��һ��ˮ����Ǻ��һ�ڣ�����\n\n" NOR,
    HIG "��е�һ���Σ���\n\n" NOR,
    HIG "����������˹�ȥ��\n\n" NOR,
    HIG "��ӻ����������������Լ�����һ��İ���ĵط��� \n\n" NOR,
});

void create()
{                           
	set("short", RED"�ɻ���ˮ��"NOR);
	set("long", @LONG
   	 �������ɻ���ˮ�ף�������߲��㣬ֻ����ϡ����һЩ���㣬����
ˮ��֮��Ķ���������û�����Եĳ�·��ˮ���������������ˮ(swim)��������˵��
��������������Ĺ��£���������Ц�ˡ�
LONG                            
	); 
	set("outdoors", "shuidi");                                       
  	setup();
}              

void init()
{
        add_action("do_swim", "swim");
}

int do_swim()
{
        object me;
        me = this_player();
      
//	me->move(__DIR__"liushui");  
	remove_call_out("shuidi" );
        call_out( "shuidi", 2, me, 0 );
//	me->move(__DIR__"liushui");
        return 1;
}

void shuidi(object who, int stage)
{     	                
        tell_object(who, make_msg[stage]);
     	
        if( ++stage < sizeof(make_msg) ) {
	        call_out( "shuidi", 2, who, stage );
		return;
        } else   
//		message_vision(RED"ok\n"NOR, who);
		who->move("/d/suzhou/liushui");
		who->add("kee", -200);
		who->add("gin", -150);
        tell_object(who, YEL "������ͣ������!\n" NOR);
	return;
}
 

