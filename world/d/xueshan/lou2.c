//lou2.c 
//by dwolf                   

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"��ѩ��¥"NOR);
        set("long", @LONG
	  �����ȫ����̴��ľ����ġ�һ�����̴��Ʈ����.ʹ���Ŀ����ġ�����
����һ���ֻ�, д�������Ƿǳɰ�תͷ�գ���ɽ�����ڣ�����Ϧ���졣��
LONG
        );
        set("exits", ([
        "down" : __DIR__"lou.c",
        ]));
      	setup();
}
            
/*void init()
{
    add_action("do_push", "push");
}

int do_push(string arg)
{
        object me;
	object obj;
	object ob;
	ob = this_player();
        
        if ( !arg || arg != "wall" )
                return notify_fail("��Ҫ��ʲ��?\n");
        
        me=this_player();
        
        if ( ((int)me->query("force") < 500) ||
             ((int)me->query("max_force") < 500) ||
             ((int)me->query("jiali") < 50 ) ) { 
                tell_object(me, "�������̫��ร�\n");
                return 1;
        }

        else if( ((int)me->query("kee")<200))
             {tell_object(me, "��������̫��ร�\n");  
              return 1;
             }
 
        me->receive_damage("gin",20);
        me->receive_damage("kee",60);
        message_vision("$N�����ƻ��ǽ��,ǽ�ڶ���һ��\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("ǽ�ڿ���,$N��ǽ�ں������˳�ȥ\n",me);
                me->move(__DIR__"llou");
                message("vision","$N��ǰ��һ��¥�����顰¥��¥.\n",environment(me),me);
        	tell_room(__DIR__"lou2","��һ��,ǽ���ֻص�ԭ��,����ڷ�ס��\n");
                return(1);
        }
        return(1);
}
        */


                                                
