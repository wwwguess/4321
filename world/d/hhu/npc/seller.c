// clother.c
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("李厨师",({"cooker","seller","li"}));
        set("title","掌勺厨师");
        set("gender", "女性" );
        set("age", 29);
set("long","她看着挺和蔼的，其实这里的菜价也很黑，她就是这个菜价的执行者\n南京高校的食堂都是这样，没什么好奇怪的\n");
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
"here": "这里是河海大学学生城，没钱的学生莫进来！！！\n",
"name": "在下河海第一快刀手，闺名不能告诉你\n",
"食品": "偶这里要什么有什么，价钱嘛，哼哼",
        ]) );
        
        set("vendor_goods", ([
        "南京板鸭(duck)":__DIR__"obj/food1",
        "麻辣鸡丝(chicken)":__DIR__"obj/food2",
        "金陵干啤(beer)"   :__DIR__"obj/beer",
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
			say( "李厨师说：这位"
                                + RANK_D->query_respect(ob)
                                + "，您需要什么？\n");
                        break;
                case 1:
say("李厨师神秘兮兮地说：啊要河海大的金龙卡\n");
                        break;
                case 2:
say("李厨师告诉你：偶老家在鱼花台区\n");
                        break;
        }
}

