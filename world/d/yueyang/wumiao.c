// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>
#include <login.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
	�����Ǻ��е�ʿ�Ǹ����������£������飩�Ĵ��.  ����
����ʢ,���������ϳ�ɱ����, ���е�ʿ�Ǵ����˲ơ�һ����ʦ����
�������
LONG
	);

	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");

	set("objects", ([
	__DIR__"npc/keeper" : 1,
	"/obj/magic/denotation.c":1,
	]));

	set("exits", ([
		"east" : __DIR__"beidajie2",
//		"up" : __DIR__"wumiao2",
//		"northwest": "/d/wizard/guest_room",
	]));
//       create_door("northwest", "����", "southeast", DOOR_CLOSED);  

	setup();   
    
}

void init()
     { add_action("do_fashi","fashi");
     }


int do_fashi(string arg)
{                
        object me;
   	object obj; 
	me=this_player();
        if (!arg) return notify_fail("��ҪΪ˭�����£�\n");
        obj = find_player(arg);
	if(!obj) return notify_fail("����˲�������....��\n");
        	if(obj->is_ghost() )	
                {if(me->query("gin")<110) return notify_fail("��ľ�������.\n");
                 if((me->query_skill("buddhism",1)<30) && (me->query_skill("daguanming",1)<30) && (me->query_skill("taoism",1)<10)) return notify_fail("��ķ𷨻��������.\n"); 

                obj->reincarnate();
		 obj->move(REVIVE_ROOM);
                 message_vision("$nͻȻһ�³�����$N��ǰ,թʬѽ!!!!!\n",me,obj);
        me->save();
	
                 
                 me->receive_damage("gin",100);
                 return 1;}
                 return notify_fail("���ܳ��Ȼ���.....\n");
}
