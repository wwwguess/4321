// shijie2.c ʯ��
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
		"southeast" : __DIR__"shijie1",
		"northup" : __DIR__"shijie3",
	]));
	setup();
	replace_program(ROOM);
}


