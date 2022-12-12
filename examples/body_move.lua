print("Welcome to Nature 2D ...")

b = nature.newBody(2, 3, 5)


function update()
    
    print(b)
    b:applyForce(10, 10)
    print(b)
    b:update()
    print(b)
    
    obj = draw.Body(b)
    obj.Color = draw.RED
    obj.Outline = 1
    obj.Fill = draw.GREEN

end

update()
