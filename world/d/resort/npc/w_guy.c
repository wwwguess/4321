inherit NPC;

void create()
{
        set_name("���۹�", ({ "oldguy" }) );
        set("gender", "����" );
        set("age", 65);
        set("str", 46);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);

        set("attitude", "peaceful");

        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 99999);
        set("sen", 3000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 300);
        set("force", 300);
        set("max_mana", 300);
        set("mana", 300);

        set("long",     "���۹��������壬ʲôҲ����\n");


        set("combat_exp", 999999);

        set_skill("unarmed", 120);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);

        set_skill("qidaoforce", 100);
        set_skill("meihua-shou", 80);
        set_skill("fall-steps", 10);

        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");

        setup();

        carry_object(__DIR__"obj/wqi")->wield();
        carry_object(__DIR__"obj/bcloth")->wear();
}

