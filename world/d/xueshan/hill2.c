//room: hill2.c
//by dwolf  

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIW"ѩɽ��"NOR);
        set("long",@LONG
	  ����ǰͻȻ������һ��ˮ�س���������ǰ��һ���ʯ�����ڳ��ԣ�������
�����֣�ѩɽ������Զ��ѩˮ�ڻ��γɵ�ˮ��������£���������ˮ������������
�㷢���ٲ�������������������ֱͨ�����죬�ٲ��������.��ɽ�����������ɼ�һ��
Ͽ�ȡ�
LONG
       );
       
       set("exits", ([ 
                "down" : __DIR__"road2",
                      ]));
        set("outdoors", "mountain");
        setup();
}

void init()
{
        add_action("do_hold", "hold");  
}

int do_hold(string arg)
{             

	object me;
	me = this_player();

        if( !arg || arg!= "����" )
                return notify_fail("��Ҫץסʲô��\n");
        message_vision("$N��������Զ��������ץȥ....\n\n",me);
        if( random((int)me->query_skill("dodge")) < 100 ) {
        message_vision("\n$Nֻ�е�ʱ��һ��Ť��������һ��İ���ĵط���\n\n",me);  
        me->move(__DIR__"jqgdi");        
      	} else {
        message_vision("$N����������ǰ��������һ��ɽ����\n\n",me);
        me->move(__DIR__"halfhole");  
        }
        return 1;
}

