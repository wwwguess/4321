// Room: /d/new_taohua/hangluting.c

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����һ����֦��ɵ���ͤ��ͤ�Ϻ���ǡ�����ͤ�����֣��������ŷ�
���������ǡ��һ�Ӱ����񽣣��̺�������������䡣ͤ�з�����̨��
���Σ�ȫ�Ƕ���֮��ֳ�����֮��.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "southeast": __DIR__"houhuayuan", 
  "west" : __DIR__"dashi",
  ]));


	setup();
	replace_program(ROOM);
}
