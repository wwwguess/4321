#include <room.h>

inherit ROOM;

void create()
{
	set("short","ɽ·");
	set("long",@LONG
����һ�λ��ߵ�ɽ·����Ȼ���������߹��������Ƕ��͵�
ɽ�ڣ�ɽ�������ǵĳ��ż���С��������������׵����£�
��ϸһ�����·���������������ˮ����ɽ·���ϱ���һ��ɽ��
�ں����Ŀ���������ľ�ɫ��ɽ·һֱ�����ѡ�
LONG
);
	set("exits",([
	"south":__DIR__"cave2",
	"north":__DIR__"mpath1",
	]) );
	setup();
	replace_program(ROOM);
}

