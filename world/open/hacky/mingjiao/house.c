// Room: /d/mingjiao/house.c

inherit ROOM;

void create()
{
	set("short", "Сľ��");
	set("long", @LONG
������һ�����õ�Сľ�ݣ���Ȼ��ª�����Ƕ����ڷŵĺ����룬һλ����
    �����������С�ǽ���м����ֻ���picture)���������������������������֡�
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "picture" : "�㿴������������֡�
",
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiaozhen",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/laozhe" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
