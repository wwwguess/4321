// Room: /d/temple/corridor3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����վ�ڻ���ת�ǵĵط�, ���ȴ����������ϱ߶�ȥ��������
�Ķ�����һ���᷿��������һ��������ʯ���С����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"road1",
		"south" : __DIR__"corridor7",
		"west" : __DIR__"corridor5",
		"east" : __DIR__"restroom2",
]));

        create_door("east","ľ��","west");

	setup();
}
