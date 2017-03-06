inherit NPC;
inherit F_VENDOR;

void create()
{
      object ob;

        set_name("�ջ���", ({ "Huei Ru","huei","huei ru" }) );
        set("gender", "Ů��" );
        set("age", 27);
        set("long",
"����һλ��Ů�����Ǻ��������������ƣ��������۾���\n"
"��׵����ݡ���ɫ���Σ����Ʈ�ݣ������Ķ���\n");
        set("combat_exp", 70000);
        set("force",1000);
        set("max_force", 1000);
        set_skill("force",10);
        set_skill("dodge", 30);
         set_skill("stormdance", 30);
        map_skill("dodge","stormdance");
        set_skill("unarmed", 10);
        set("inquiry", ([
            "buy":          (: this_object(), "ask_buy" :)
        ]) );
        set("chat_chance", 7);
        set("chat_msg", ({
"�ջ���˵����С�����⣡  ������������ӭ����(order)��\n",
"�ջ���������ͷ����\n",
"�ջ����۾�գѽգ�����㡣\n"
        }) );
        create_family("����ׯ",2,"����");
        setup();
        ob = carry_object("/obj/example/dagger");
}

void init()
{
        object ob;

        ::init();
        add_action("do_list","list");
        add_action("do_buy","order");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
         say( "�ջ���˵������λ" + RANK_D->query_respect(ob)
             + "��Ҫ��Ҫ��Щ����ѽ��\n");
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("�����Ҳ�Ҫ�������\n");
        else if( val > 100 ) {
                if( (who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", - 
(random((int)who->query("kar")) + val/1000) );
        }
        say( "�ջ���˵������л��λ" + RANK_D->query_respect(who)
                + "������һ���ᱣ����ġ�\n");

        return 1;
}

int ask_buy(object who)
{
        write("С�����⣬��Ǯ���Թ�����\n"
              "����ϸĿ :  list \n"
              "������Ʒ :  order [<��Ʒ����>]  \n");
     return 1;
}

int do_list(string arg)
{
      write( "������������Ʒ : \n"
          "\n ��λ������ (silver) \n \n"
             "No.    �۸�.      ���� \n"
             "1. [ ����   ]  ��ȹ (skirt) \n"
             "2. [   ʮ��   ]  Ů���� (wine) \n"
             "3. [ ��ʮ��   ]  ¹ƤСѥ (boots) \n"
             "4. [ ��ʮ��   ]  �ɶ�  (sen-bean) \n"
             "5. [ һ����   ]  �󻹵� (heal pill) \n \n"
    "����㲻˵����ʲô!���Ҿ�����Ů�����! \n \n"
            );
      return 1;
}

int do_buy(string arg)
{
       string name,unit,objname;
       int amount,bv;
       object obj, player,from_ob,who_ob;

       amount = 10;

       player = this_player();
       obj = new("/d/latemoon/sell/wine");
    if(!arg )
          return notify_fail("��Ҫ��ʲô����ѽ?˵�����! \n");
       else {
      if ( arg == "wine")       { obj= new("/d/latemoon/sell/wine");
                                  amount = 10; }
      if ( arg == "skirt")     { obj= new("/d/latemoon/sell/skirt");
                                 amount = 5; }
      if ( arg == "boots")      { obj= new("/d/latemoon/sell/boots");
                                  amount = 20; }
      if ( arg == "sen-bean")   { obj= new("/d/latemoon/sell/bean");
                                  amount = 50; }
      if ( arg == "heal pill")   { obj= new("/d/latemoon/sell/pill");
                                   amount = 100; }
       from_ob = present("silver_money",this_player());
       if( !from_ob )    return notify_fail("������û������Ү��\n");
       if( (int)from_ob->query_amount() < amount )
       return notify_fail("������û����ô������Ү��\n");
          from_ob->add_amount(-amount);
          obj->move(player);
       }
       name = (string)this_player()->query("name");
       unit = (string)obj->query("unit");
       objname = (string)obj->query("name");

       tell_room(environment(this_object()),"�ջ����"+name
              +"һ"+unit+objname+"\n");
             say ("�ջ���˵����лл��!�´�����! \n");

       return 1;
}
void die()
{
        object *inv;
        int i;
        revive();
        command("grin");
        command("shake");
        command("say ��������ɱ�����ҵ�!! ");
        command("say ��..");
        inv = all_inventory(environment(this_object()));
        i = sizeof(inv);
        while (i--)
            if (living(inv[i])) inv[i]->remove_all_killer();
        return;
}
