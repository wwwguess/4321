// Room: /d/heimuya/.c
// write by: dfbb 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","·��");
	set("long", @LONG
����һ��·��,������ʮ�����ƽ���ݱ�����,��������ʮ�����������
����̲��·�����˴Ҵ�ææ�Ķ����Ž��ǡ����Ϸ���ͨ��һ���������
���ɴ˵��������·����һ�ҿ�ջ��

LONG
	);

	set("exits", ([
		"north" :__DIR__"bdcm",
                "northwest" :__DIR__"xxt1",
                "west" :__DIR__"kezhan",
                "southwest" :__DIR__"yidao1",
	]));

	set("outdoors", "heimuya");
	setup();
	replace_program(ROOM);
}

