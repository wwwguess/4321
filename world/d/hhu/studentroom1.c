// Room: /d/hhu/studentroom1.c

inherit ROOM;

void create()
{
	set("short", "ѧ��һ��");
	set("long", @LONG
ѧ��һ����1994���¸ǵģ�ѧ��4����һ�����䣬
ÿ����������һ̨�ʵ磬�����൱�ĺá�����
���ӵ����˲����˵�ѧϰ����Ϣ������MUD��Ϸ
һ�����������˳������С�������
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hhu1road3",
  "north" : __DIR__"studentroom2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/student_1.c" : 2,
]));
	set("no_clean_up", 0);

	setup();
}
