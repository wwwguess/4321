// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "��լ");
	set("long", @LONG
����һ���ª����լ, �ݶ���Լ�����Կ���һЩ�ƶ�. ǽ�Ƕ�
��Щ���, ǽ���ϻ����Կ�����Ѭ�ĺۼ�. ����һЩ��ª�ļҾ���
���ڿտյ�����.

LONG
	);
    set("exits", ([
    "south" : __DIR__"field0",
]));
	set("no_clean_up", 0);
	set("objects", ([
        __DIR__"npc/oldman" :1,
        __DIR__"npc/oldwoman" : 1,
		]) );

	setup();
	replace_program(ROOM);
}
