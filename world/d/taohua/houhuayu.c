// Room: /d/new_taohua/houhuayuan.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǰ����һ��Ƭ���������а���ʢ�ţ�����������Ҷ���һ��
Сʯ�������������룬�ֲַ����Ĵ����졣   
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "north": __DIR__"yonglu3",
  "south" : __DIR__"yonglu2",
  "west" : __DIR__"liangongfang",
  "east": __DIR__"yonglu6",
  "northwest": __DIR__"wangluting",
]));
	set("outdoors", "new_taohua");

	setup();
	replace_program(ROOM);
}
