// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ϻ����ײ������ܹ��߻谵����Ӱ�λΣ��ƺ��м����ڰ��Ķ���
������ߣ�ͨ������˷���  һλ����ؤ�����ֵ��������еĵ��ϡ�����
�����㷢��ǽ���ϻ��ŷ��ֲڵ�·�߲�ͼ��map����
LONG
	);

	set("exits", ([
		"up":__DIR__"inhole",
"down":__DIR__"chuchang",
//		"down":__DIR__"chuchang",
		"2":__DIR__"zlandao1",
	]));

	set("item_desc",([ "map" : 
		"���ڶ���ͨ�����֡�\n" 
	]));

	set("objects",([
		CLASS_D("gaibang") + "/liang" : 1,
	]));

	setup();
	replace_program(ROOM);
}



