// Room: /d/village/road2.c

inherit ROOM;

void create()
{
	set("short", "����·��");
	set("long", @LONG
�����Ѿ������չغ�Զ�ˣ�˳�Ż�����������ߣ���ɫ����������
������ľ͸��ϲ�˵��̣�������ȥ��ɽ��ˮ����һ�ɹ��ھ�ɫ�����ܿ�
��ɢ��ķ��ݣ�ũ���ˮ�����������ÿ͡����ˡ�ũ��Ҳ���ˡ�������
�����Ϸ������죬�����ǽ���һ����ׯ��С·��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : "/d/chuenyu/croad1",
  "north" : __DIR__"road1",
  "west" : __DIR__"road3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/trader1" : 2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
