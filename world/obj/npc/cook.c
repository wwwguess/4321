inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�ϰ���", ({ "cook" }) );
	set("gender", "Ů��" );
	set("age", 22);
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("inquiry", ([
		"work" : "����Ҳ����Щϴ����ˢ��֮��Ļ��Ҫ�ǲ�Ը��ɵĻ�ȥ��Ժ�������˰�!",
		"����" : "����Ҳ����Щϴ����ˢ��֮��Ļ��Ҫ�ǲ�Ը��ɵĻ�ȥ��Ժ�������˰�!",
		]));
        set("vendor_goods", ([
                "�߶�" : "/d/hua/obj/dust1",
                "��õ�嶾" : "/d/hua/obj/dust2"
        ]) );
	
	setup();
}

void init()
{
        object ob;

        ::init();
        add_action("do_vendor_list", "list");


}

