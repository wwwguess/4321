#include <room.h>

inherit ROOM ;

void create()
{
        set("short","����");
        set("long",@LONG
����һ�����,����û���κγ���,�㲻������Ҫ���˳���,��Ȼ,�㷢��
Զ����һ���ʯ(stone)����һ��,�߽�һ��,�ƺ�������(push)һ�¡�
LONG
);

        set("outdoors","green");
        set("no_clean_up",0);
        setup();
//        replace_program(ROOM);
}

void init()
{
//        ::init();
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me;
        
        if ( !arg || arg != "stone" )
                return notify_fail("��Ҫ��ʲ��?\n");
        
        me=this_player();
        
        if ( ((int)me->query("force") < 560) ||
             ((int)me->query("max_force") < 560) ||
             ((int)me->query("force_factor") < 40 ) ) { 
                tell_object(me, "�������̫��ร�\n");
                return 1;
        }

        me->receive_damage("gin",20);
        me->receive_damage("kee",60);
        me->receive_damage("sen",20);
        message_vision("$N�����ƻ�Ĵ���ʯ,����ʯ����һ��\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("����ʯ������,$N�Ӵ���ʯ�����С�����˳�ȥ\n",me);
                this_player()->move(__DIR__"entrance");
                message("vision","$N��ɽ���ϵ�һ���������˳���\n",environment(me),me);
        	tell_room(__DIR__"closed","��һ��,����ʯ�ֹ��˻���,�Ѷ����ַ�ס��\n");
                return(1);
        }
        return(1);
}


