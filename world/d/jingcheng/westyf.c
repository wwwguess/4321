#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIW"��Ӫ��"NOR);
	set("long", @LONG
Ӫ����տյ�����ֻ�м��Ŵ��̺�һ�Ŵ�������Ա������Χ�������
��̸���ۣ����Ķ��ǵ���������սʱ�ĺպ�ս����ǽ�Ϲ����ŵ񹭣�
���������������û���ٽ�����ǿ��������Ź��ġ�
LONG         
	);

	set("exits", ([ 
 "east"  :__DIR__"ql4",
 	]));
	setup();
	
}

