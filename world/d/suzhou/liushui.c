//ROOM:/d/suzhou/liushui.c
//by dwolf
//97.11.8 
         
#include <ansi.h>
inherit ROOM;    

string *make_msg = ({
    HIG "���ڼ���������������������\n\n" NOR,
    HIG "��Ǻ��һ��ˮ����Ǻ��һ�ڣ�����\n\n" NOR,
    HIG "��е�һ���Σ���\n\n" NOR,
    HIG "ͻȻ�㿴��һ�������������!! \n\n" NOR,
});

void create()
{                           
	set("short", YEL"����ˮ"NOR);
	set("long", @LONG
       ���ڼ�������������ʱǺ��һ��ˮ���㻹����������
����(swim)?
LONG
	);                                        
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

//        me->move(__DIR__"shuidi");  
        remove_call_out("shuidi" );
        call_out( "shuidi", 2, me, 0 );
//	me->move(__DIR__"shuimian");
        return 1;
}
void shuidi(object who, int stage)
{                       
        tell_object(who, make_msg[stage]);
        
        if( ++stage < sizeof(make_msg) ) {
                call_out( "shuidi", 2, who, stage );
                return;
        } else   
//                message_vision(RED"ok\n"NOR, who);
                who->move("/d/suzhou/shuimian");
                who->add("kee", 100);
                who->add("gin", 100);
        tell_object(who, YEL "�����������˻�����\n" NOR);
        return;
}

