// Room: /d/hhu/studentroom1.c

inherit ROOM;

void create()
{
        set("short","ѧ������");
	set("long", @LONG
ѧ��������1992��ǵģ�ѧ��4����һ�����䣬
ÿ����������һ̨�ʵ磬�����൱�ĺá�����
���ӵ����˲����˵�ѧϰ����Ϣ������MUD��Ϸ
һ�����������˳������С�������
��ʱ�����MUD��Ԫ���Ƕ�ס�����ÿ���
������ţ���ڶ�����ǿ����дMUD������
��������Զ��ס���
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
]));
	set("exits", ([ /* sizeof() == 1 */
  "south":__DIR__"studentroom2",
  "northeast" : __DIR__"hhusport",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/student_1.c" : 2,
   "/obj/money/silver" : 2,
]));
	set("no_clean_up", 0);

	setup();
}
