// guildhall.c

inherit CLASS_GUILD;

void create()
{
	set("short", "ˮ�̸�����");
	set("long", @LONG
������ˮ�̸���������򵥵ĳ�����͸��һ����󲻷������ɣ�һ
����ڵ�̫ʦ�ζ����ڴ������룬����ͬʱҲ�ǡ����ߡ������µ�����
��ÿ�������ʮ�߶�Ҫ��ˮ�̸���ġ���̨����ѡ����������Ȼ������
����е�λ��䡣����Կ������ߵ�ǽ�Ϲ���һ��ľ��(sign)���ƺ�д
��һЩ�йس�Ϊһ�����ߵ����
LONG
	);
	set("exits", ([
		"south" : "/d/waterfog/entrance",
	]));
	set("item_desc", ([
		"sign": @TEXT
Ҫ��Ϊһ�����߲����ѣ�ˮ�̸���ʱ��ӭ�κ�������֮�˳�Ϊ���ǵ�
һ���ӣ�ֻҪ�����(join)����ͬ�ˣ��Ϳ�����ͬ���еĸ������ɰ�ʦ
ѧ�ա�
TEXT
	]) );

	set("objects", ([
		__DIR__"champion":1,
		__DIR__"master":1
	]) );
	set("valid_startroom", 1);
	setup();
	call_other("/obj/board/fighter_b", "???");
}
