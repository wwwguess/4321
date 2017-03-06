// Room: /d/oldpine/waterfall.c

inherit ROOM;

void create()
{
	set("short", "�ٲ�ǰ");
	set("long", @LONG
��������վ���ٲ�ǰ��һ��Сˮ̶�ˮ̶��Լ��ɼ��أ��Ͳ���
�ˣ�һ����������ٲ�(waterfall)�������ɸߵ������ϳ弤���£���
����ȫ��ʪ͸��ˮ̶���涼�����ʵ�ɽ��(cliff)����Χ��ֻ��������
��һ��ɽ�����Գ�ȥ��
LONG
	);
	set("item_desc", ([
		"waterfall":
			"����ٲ�ˮ�Ʋ����Ǻܴ󣬵��Ǹ߶�ȴ���ߣ�ˮ�齦���������\n"
			"����������ۡ���ע�⵽�ٲ������ƺ���ʲô�����ڷ����⡣\n",
		"cliff":
			"ˮ̶���ܵ�ɽ�ڶ��������ɸߣ���Ҫ����ȥ���϶��������롣\n"
	]) );
	set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/oldpine/riverbank2",
]));
	set("resource/water", 1);
	setup();
	replace_program(ROOM);
}
