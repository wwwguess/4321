// liaowang.c 
// by yuer

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
      ����������Կ���ɽ�µľ��������������۲�ɽ�����εĵط���
LONG
	);
        set("outdoors", "mingjiao");

	set("exits", ([
	
	       "east" : __DIR__"banshanmen",
	]));
	setup();
	replace_program(ROOM);
}


