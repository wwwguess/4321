// Room: /d/sanyen/gate.c

inherit ROOM;

void create()
{
	set("short", "ɽ����ɽ��");
	set("long", @LONG
��������ɽ���µ�ɽ�ţ�������һ������ɽ���������ɽ��������
�Ķ�������Զ���������е��Ϸ������Ǻ���ҽ��ͨ�񣬲����ܹ����ݵ�
���ظ�����ɽ���������ý�̻Իͣ�ׯ����ΰ�����ɽ���¹�ģ��Ȼ��
�����ǵİ�����Ժ����������ȴ�Ǵ�ö��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : "/d/sanyen/sroad2",
		"east" : "/d/sanyen/front_yard",
	//	"south" : "/d/latemoon/sroad1"
	]));
	set("objects", ([ /* sizeof() == 1 */
		"/d/sanyen/npc/greeting" : 2,
	]));
	set("outdoors", "sanyen");

	setup();
	replace_program(ROOM);
}
