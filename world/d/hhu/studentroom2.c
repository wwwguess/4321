// Room: /d/hhu/studentroom1.c

inherit ROOM;

void create()
{
        set("short","ѧ������");
	set("long", @LONG
ѧ��������1993���¸ǵģ�ѧ��4����һ�����䣬
ÿ����������һ̨�ʵ磬�����൱�ĺá�����
���ӵ����˲����˵�ѧϰ����Ϣ������MUD��Ϸ
һ�����������˳�������,����һ��Ů��¥��¥
�³��ܿ����쳤�˲��ӵ��˵ĳ�������......
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"studentroom1",
  "north" :__DIR__"studentroom3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/student_2" :3,
]));
	set("no_clean_up", 0);

	setup();
}
