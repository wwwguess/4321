
#include <room.h>
inherit ROOM;

void create()
{
     set("short", "׺����");
	set("long", @LONG
��������ׯ�õ����Ǿ��޵ĵط�, ��Ի��׺�������򵥵Ĳ��ü���
һ��̴��¯, ������������һ������(ponder)�ĺó���������������
��һ�����µ���Ϣ, ʹ�˺����׽������ҵľ��硣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"upstar3",

]));

    set("objects", ([
        __DIR__"npc/huei" : 1,
     "/d/latemoon/obj/cake" : 1,
    ]) );
    create_door("north","ľ��","south", DOOR_CLOSED);
	setup();
}
void init()
{
       add_action("do_ponder","ponder");
}
int do_ponder(string arg)
{
       object who;

       who = this_player();
       message_vision("$N˫�ֺ��ƣ����������ڵ��ϡ�\n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 7 ) );
       message_vision("$N�ݷ��Ľ�Ϊ��ϴ�����! \n" , who);
    return 1;
}
