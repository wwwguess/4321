// Room: /u/k/karrimor/temple/corridor7.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������һ������֮��, �������ϱ�����, ���˷ֱ����������
����������һ�����ݷ��յ��쾮, ��������һ���᷿��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
     "north" : __DIR__"corridor3",
     "south" : __DIR__"corridor1",
     "west" : __DIR__"inneryard",
     "east" : __DIR__"restroom1",
]));

    create_door("east","ľ��","west");

	setup();
}
