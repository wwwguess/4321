// shijie1.c ʯ��
// by yuer

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
    ������һ����ʵ��ʯ���ϡ�һ�����ͱڣ�һ�������£�
    ̧ͷ��Լ�ɼ������������е������ܶ������������ʮ���ն�

LONG
	);
        set("outdoors", "mingjiao");

	set("exits", ([
    "south" : __DIR__"xiaozhen",
		"northwest" : __DIR__"shijie2",
	]));
	setup();
	replace_program(ROOM);
}


