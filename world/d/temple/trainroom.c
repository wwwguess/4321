// Room: /u/k/karrimor/temple/trainroom.c

inherit ROOM;

void create()
{
    set("short", "����\��");
	set("long", @LONG
����վ��һ������Ĵ󷿼���, ������éɽ�ɵ��Ӵ��������ĵ�
��, ������������һ�ɹɺ���ζ�����ܵ�ǽ���ϻ���һ��������Ѩ��
ͼ������ǽ�ڵĵ��������һ���������õ�ľ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
     "south" : __DIR__"corridor4",
]));

     set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/yang" : 1,
     __DIR__"npc/taoist" : 1,
     __DIR__"npc/taoist2" : 1,
     ]) );

    create_door("south", "ľ��", "north");
	setup();
}
