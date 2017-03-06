// Room: /d/choyin/s_street1.c

inherit ROOM;

void create()
{
	set("short", "���Ź㳡");
	set("long", @LONG
������������س�����һ���㳡�������ǹ�ͨ�س��ϱ��ŵĸ���
�������������һ���������Ƶĺ����������������㳡��ֻ�����յģ�
���Ǻ�«�ģ������˵ģ���ɫС��������ȥ���㳡������һ�ڴ󾮣���
��������������ֻ���ӹ���ȡˮ��(drink)�����ŵ���¥��Ϊ����ǰ�Ľ�
�����������ţ�����Ƶ����ߵ��ظ��������ڵĲ�ƽ�֣����ڹ㳡����
�����һ������ͨ��������������ׯ�����ϱ�һ�����Ľֵ���������
ͨ�����⣬�㳡��������һֱ���쵽��ƽ�֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"bridge1",
		"north" : __DIR__"s_street2",
		"west"	: __DIR__"s_street4",
		"southwest" : __DIR__"sw_road1",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/cucurbit_seller" : 1,
		__DIR__"npc/dumpling_seller" : 1,
	]));
	set("resource/water", 1);
	set("outdoors", "choyin");
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	if( (int)this_player()->query("water") >=
		(int)this_player()->max_water_capacity() )
		return notify_fail("���Ѿ���Ҳ�Ȳ���һ��ˮ�ˡ�\n");
	message_vision("$N�ھ����ñ���Ҩ��ˮ���˼��ڡ�\n", this_player());
	this_player()->add("water", 20);
	return 1;
}
