// Room: /d/heimuya/.c
// write by: dfbb 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","��������");
	set("long", @LONG
����ƽ���ݱ����ǵĳ���,��Ŵ����ש���ĳ�ǽ����Ȼ�Ѿ����ϰ������ʷ��ȴ��
Ȼ�ǳ����,��ʵ�Ĵ��Ž�����.
LONG
	);

	set("exits", ([
		"south" :__DIR__"sancha",
                "northeast" : "/d/heimuya/dayidao1",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

