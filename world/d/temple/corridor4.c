// Room: /u/k/karrimor/temple/corridor4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����վ�ڻ���ת�ǵĵط�, ���ȴ��������߼��ϱ߶�ȥ���ڱ���
��һ�����, ���洫������߳�ȵ�������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
     "north" : __DIR__"trainroom",
     "south" : __DIR__"corridor6",
     "east" : __DIR__"corridor5",
]));

    create_door("north", "ľ��", "south");
	setup();
}
