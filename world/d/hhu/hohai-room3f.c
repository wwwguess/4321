// Room: /d/hhu/hohai-room3f.c

inherit ROOM;

void create()
{
	set("short", "�Ӻ���");
	set("long", @LONG
�Ӻ����ǺӺ���ѧ�ڵĴ���֮һ
    ����У���İ칫�ң����˲��������롣
LONG
	);
        set("no_fight","1");
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"hohai-room2f",
]));
	set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/chairman" :1,
]));
	set("no_clean_up", 0);

	setup();
}
