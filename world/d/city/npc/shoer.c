// shoer.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("���ƹ�", ({ "seller" }) );
        set("title", "Ь��");
        set("gender", "Ů��" );
        set("age", 30);
        set("long", "���ƹ��ǲ��ѿ���Ů�ˣ�һֱ��Ӫ���洫Ь�����⡣\n");
        set("combat_exp", 220000);
        set("attitude", "friendly");
        set_skill("unarmed", 150);
        set_skill("dodge", 120);
        set_skill("sword", 120);

        set("inquiry", ([
                "Ь" : "����Ҫʲô���ģ�",
        ]) );
       set("vendor_goods", ([
                "¹ƤСѥ": __DIR__"obj/deer_boot",
                "��Ƥսѥ": __DIR__"obj/xiang_boot",
                "�廨Ь"  : __DIR__"obj/flower_boot",
        ]) );

        setup();
        add_money("gold", 9);
        add_money("coin", 300);
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/wuqing_sword")->wield();
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
                        say( "���ƹ������λ"
                                + RANK_D->query_respect(ob)
                                + "������Ҫʲô����Ь����\n");
                        break;
                case 1:
                        say( "���ƹ������һ�ۣ������˵������������\n");
                        break;
                case 2:
           say( "���ƹ��Ȼ��˵�����þ�ûȥ�����ˣ���֪�����Ƿ񻹺���\n");
                        break;
        }
}

