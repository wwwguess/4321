inherit NPC;

void create()
{
     set_name("���", ({"ching-fong", "ching", "fong"}) );
     set("gender", "����");
     set("age", 43);
     set("class", "taoist");
     set("title", "éɽ�ɵ���������");
     set("long", "һλ����רע�ĵ�ʿ, ������ֵ�����زؾ�¥��\n");
     set("attitude", "peaceful");
     set("combat_exp", 48000);
     set("chat_chance_combat",50);
     set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "feeblebolt" :),
        }) );

     set("spi", 28);
     set("com", 30);
     set("cor", 25);
     set("con", 26);

     set("force", 700);
     set("max_force", 700);
     set("force_factor", 5);
     set("mana", 1800);
     set("max_mana", 1800);
     set("atman", 900);
     set("max_atman", 900);
     
     set_skill("unarmed", 30);
     set_skill("dodge", 35);
     set_skill("force", 30);
     set_skill("gouyee", 50);
     set_skill("parry", 35);
     set_skill("spells", 75);
     set_skill("necromancy", 80);
     set_skill("magic", 35);
     set_skill("taoism", 90);

     map_skill("magic", "taoism");
     map_skill("spells", "necromancy");
     map_skill("force", "gouyee");

     setup();

     carry_object(__DIR__"obj/robe1")->wear();
     carry_object(__DIR__"obj/jade_hat")->wear();
}
