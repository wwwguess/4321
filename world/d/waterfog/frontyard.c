// Room: /d/waterfog/frontyard.c

inherit ROOM;

void create()
{
	set("short", "ˮ�̸�ǰ");
	set("long", @LONG
��������վ��һ���ߴ��¥��ˮ�̸�ǰ������ɫ�����ߺͰ����
�İ�ʯשʹ��ˮ�̸��ڳ�ɽ�������Ե�ʮ�����ۣ�����¥�����������
��˵���С�����֮�񡹳ƺŵ�̫��������ӹ����������������������
�����ľ�������˵��ѧ��֮�˵ĳ�ʥ�أ�һ����ʯ��������ɽ�����϶�
�£�ˮ�̸�Ĵ��ž�����ı�����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/waterfog/wpath1",
  "north" : "/d/waterfog/entrance",
  "southdown" : "/d/waterfog/stair5",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}
