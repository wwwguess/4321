// Room: /u/k/karrimor/temple/temple2.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����վ�����Ĺ۵ĺ��, �����빩����éɽ�ɿ�ɽ��ʦ����ʦ��
����, �ڻ�����·��ڷ�����������ʦ������ħʱ���õı���������
�������������������˵���λ���߳��ϱߵĺ���ľ�ſ��Կ����쾮��
LONG
	);
    set("item_desc", ([
         "door": (: this_object(), ({ "look_door", "south"}) :),
    ]) );
	set("exits", ([ /* sizeof() == 1 */
     "south" : __DIR__"corridor5",
]));

     create_door("south", "����ľ��", "north", DOOR_CLOSED);
	setup();
}
