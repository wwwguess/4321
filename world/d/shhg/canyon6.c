// Room: /d/canyon/canyon6.c

inherit ROOM;

void create()
{
	set("short", "���չعȵ�");
	set("long", @LONG
���ʵ������������չ����࣬�м��ǲ��������Ĺȵأ�����������
���ĺõط�����ô������������Ĺ�ϵһֱ�ǳ����ͣ���˴���������
�򿪡����ŵĺ����и��ܴ�Ļ�еװ��(machine)��������ͨ�����ǵ�
·�������ͳ������չء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"canyon7",
  "north" : __DIR__"canyon5",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "mechine" : "���Ǹ��ܴ�Ľ��̣������ǿ��������õġ�\n",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
