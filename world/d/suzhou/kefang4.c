inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
        ���ǿ�ջ�Ŀͷ��������м������䣬��ϡ���������ǵ�˵Ц����������Գ��
���㲻�ɼӿ��˽Ų����ҵ�һ��յĵ��䣬׼��˯����
    ����Ψһ�ĳ����� west��
LONG
	);

	set_light(0);
	set("sleep_room", "1");
	set("no_fight", "1");
        set("hotel",1);

	set("exits", ([
		"west" : __DIR__"kefang2",
	]));

	setup();
}
/*
int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}

*/
