// banshanmen.c 
// by yuer

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
      ���������ܶ�ĵ�һ���ؿ���һ�����ͱڣ�һ�������£�
     ����һ�򵱹أ����Ī��������ʮ���ն�
LONG
	);
        set("outdoors", "mingjiao");

	set("exits", ([
		"southdown" : __DIR__"shijie3",
		"northup" : __DIR__"shanlu1",
	       "west" : __DIR__"liaowang",
	]));
	setup();
	replace_program(ROOM);
}


