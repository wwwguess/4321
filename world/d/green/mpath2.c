#include <room.h>

inherit ROOM;

void create()
{
	set("short","ɽ·");
	set("long",@LONG
����һ�λ��ߵ�ɽ·����Ȼ���������߹��������Ƕ��͵�
ɽ�ڣ�ɽ�������ǵĳ��ż���С��������������׵����£�
��ϸһ�����·���������������ˮ����ɽ·�ı����ƺ�����
��ͷ��
LONG
);
	set("exits",([
	"south":__DIR__"mpath1",
	"north":__DIR__"entrance",
	]) );
	setup();
	replace_program(ROOM);
}

