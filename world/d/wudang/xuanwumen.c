// xuanwumen.c ������
// by Xiang

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
	�������ǰ��һ���ߴ��ʯ��������д�š������š������ֽ���֣���
�������Զ���þ���ɹ���ܣ��Ѿ��Ե���Щ��������������һ�����ۣ���������
һ��ʯ��·һֱͨ��ɽ�¡�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shijie3",
		"northup" : __DIR__"guangchang",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/zhike" : 1]));
	setup();
	replace_program(ROOM);
}

