inherit ROOM;

void create()
{
	set("short", "Сʯ��");
	set("long", @LONG
����һ����ͨ��Сʯ�ţ�������һ��СϪ��ˮ����Ʈ��һ���������Ļ�
�꣬������һ����ʯС·��������һƬ�������ֳ�һ����ׯ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : "/d/yulan/yulan_gate",
  "west" : "/d/yulan/road1",
]));

	setup();
	replace_program(ROOM);
}
