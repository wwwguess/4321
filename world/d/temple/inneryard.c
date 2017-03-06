// Room: /u/k/karrimor/temple/inneryard.c

inherit ROOM;

void create()
{
	set("short", "�쾮");
	set("long", @LONG
����վ�����Ĺ۵��쾮��, ������ֲ��һЩ������ľ, ��������
��������һ��ˮ�������߾��ǹ�ٺéɽ�����������˵ĵط�, �ϱ���
��һ��ǽ, ǽ����һ����Ǵ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
     "north" : __DIR__"corridor5",
     "west" : __DIR__"corridor6",
     "east" : __DIR__"corridor7",
]));

    set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/little_taoist2" : 1,
    ]) );
	set("outdoors", "temple");

	setup();
	replace_program(ROOM);
}
