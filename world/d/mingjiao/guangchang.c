// guangchang.c
// by yuer
#include <ansi.h>
inherit ROOM;


void create()
{
	set("short", "�㳡");
	set("long","�����������ܶ�Ĺ㳡�������㳡�ɴ�����ʯ�̳ɣ���Ϊƽ̹��
���������Զ������Щ���𡣴Դ�С�ݴ�ʯ��ķ�϶�г��˳������Ϸ�һ����ң�
���ɷ�������� \n\n"+ YEL "          ��     ��     ��" NOR + "\n\n");

	set("exits", ([
		"southdown" : __DIR__"damen",
		"north" : __DIR__"zoulang",
	     
	]));
      set("objects",([
		CLASS_D("mingjiao") + "/yangxiao" : 1,
            ]));

	setup();
	replace_program(ROOM);
}



