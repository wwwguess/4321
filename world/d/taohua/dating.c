// Room: /d/new_taohua/dating.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ի�亮�ã����½��ϰ�����������ܰ�Ȼ��������ֹ���٤��
ľ�����飬����ܰ��Ϯ�ˣ�������á�������һ�������������ӣ�������Щ��
�ʹ������˻�ҩʦ������ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "north": __DIR__"houting",
  "south" : __DIR__"qianting",
  
]));
	
   set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}
