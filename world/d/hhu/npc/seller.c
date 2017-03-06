// clother.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("���ʦ",({"cooker","seller","li"}));
        set("title","���׳�ʦ");
        set("gender", "Ů��" );
        set("age", 29);
set("long","������ͦ�Ͱ��ģ���ʵ����Ĳ˼�Ҳ�ܺڣ�����������˼۵�ִ����\n�Ͼ���У��ʳ�ö���������ûʲô����ֵ�\n");
        set("combat_exp",1000);
        set("attitude", "friendly");
        set("max_atman", 1000); 
        set("atman", 1000);        
        set("atman_factor", 3);
        set("max_force", 1000); 
        set("force", 1000);
        set("force_factor", 3);
        set("max_mana", 1000); 
        set("mana", 1000); 
        set("mana_factor", 3);
        
        set_skill("dodge", 120);
        set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("fonxanforce", 100);
        set_skill("fonxansword", 100);
        set_skill("chaos-steps", 100);
        map_skill("force", "fonxanforce");
        map_skill("dodge", "chaos-steps");
        map_skill("sword", "fonxansword");

        set("inquiry", ([
"here": "�����ǺӺ���ѧѧ���ǣ�ûǮ��ѧ��Ī����������\n",
"name": "���ºӺ���һ�쵶�֣��������ܸ�����\n",
"ʳƷ": "ż����Ҫʲô��ʲô����Ǯ��ߺ�",
        ]) );
        
        set("vendor_goods", ([
        "�Ͼ���Ѽ(duck)":__DIR__"obj/food1",
        "������˿(chicken)":__DIR__"obj/food2",
        "�����ơ(beer)"   :__DIR__"obj/beer",
        ]) );

        setup();
        add_money("gold", 9);
        add_money("coin", 300);
        carry_object("/obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
			say( "���ʦ˵����λ"
                                + RANK_D->query_respect(ob)
                                + "������Ҫʲô��\n");
                        break;
                case 1:
say("���ʦ���������˵����Ҫ�Ӻ���Ľ�����\n");
                        break;
                case 2:
say("���ʦ�����㣺ż�ϼ����㻨̨��\n");
                        break;
        }
}

